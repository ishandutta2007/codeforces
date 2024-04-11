

    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long double T;
    typedef long long int LL;
     
    #define st first
    #define nd second
    #define PLL pair <LL, LL>
    #define PII pair <int, int>
     
    const int N = 1e6 + 7;
    const int MX = 1e9 + 7;
    const LL INF = 1LL * MX * MX;
     
    int n;
    char in[N];
     
    void solve(){
    	scanf("%s", in + 1);
    	n = strlen(in + 1);
    	
    	int it = 1, ans = N;
    	vector <int> cnt(3, 0);
     
    	for(int i = 1; i <= n; ++i){
    		while(it <= n){
    			bool is = false;
    			for(int t = 0; t < 3; ++t)
    				is |= cnt[t] == 0;
    			
    			if(!is)	break;
    			cnt[in[it++] - '1']++;
    		}
    		
    		bool is = false;
    		for(int t = 0; t < 3; ++t)
    			is |= cnt[t] == 0;		
    		
    		if(!is)
    			ans = min(ans, it - i);
    		cnt[in[i] - '1']--;
    	}
    	
    	if(ans == N)
    		ans = 0;
    	printf("%d\n", ans);
    }
     
    int main(){
    	int cases;
    	scanf("%d", &cases);
    	
    	while(cases--)
    		solve();
    	return 0;
    }