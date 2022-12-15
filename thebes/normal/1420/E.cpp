#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 82;
int N, K, i, j, k, x, y, tmp[MN][MN*MN];
deque<pii> dp[MN][MN*MN];
vi pos;

inline int eval(pii ln,int x){
	return (ln.F-x-1)*(ln.F-x-2)/2+ln.S;
}

inline double eval(pii ln,double x){
    return (ln.F-x-1)*(ln.F-x-2)/2+ln.S;
}

inline double isect(pii ln,pii ln2){
    double lo = 0, hi = min(ln.F,ln2.F);
    while(lo+0.001<hi){
        double mid = (lo+hi)/2;
        if(eval(ln,mid)<=eval(ln2,mid)) hi=mid;
        else lo=mid+0.001;
    }
    return lo;
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		if(x){
			K++;
			pos.pb(i);
		}
	}
	dp[K][0].pb({N+1,0});
	for(i=N;i>=1;i--){
		memset(tmp,-1,sizeof(tmp));
		for(j=0;j<K;j++){
			for(k=abs(pos[j]-i);k<=N*(N-1)/2;k++){
				while(dp[j+1][k-abs(pos[j]-i)].size()>=2){
                    pii fs = dp[j+1][k-abs(pos[j]-i)].front();
                    dp[j+1][k-abs(pos[j]-i)].pop_front();
					if(eval(fs,i)>=eval(dp[j+1][k-abs(pos[j]-i)].front(),i)) continue;
					else{
                        dp[j+1][k-abs(pos[j]-i)].push_front(fs);
                        break;
					}
				}
				if(dp[j+1][k-abs(pos[j]-i)].size()){
					tmp[j][k] = eval(dp[j+1][k-abs(pos[j]-i)].front(),i);
				}
			}
		}
		for(j=0;j<K;j++){
			for(k=0;k<=N*(N-1)/2;k++){
				if(tmp[j][k]!=-1){
                    while(dp[j][k].size()>=2){
                        pii lst = dp[j][k].back(); dp[j][k].pop_back();
                        if(ceil(isect(dp[j][k].back(),lst))<=floor(isect(lst,make_pair(i,tmp[j][k])))) continue;
                        else{
                            dp[j][k].push_back(lst);
                            break;
                        }
                    }
                    dp[j][k].pb({i,tmp[j][k]});
				}
				while(dp[j][k].size()>=2){
                    pii fs = dp[j][k].front();
                    dp[j][k].pop_front();
					if(eval(fs,i)>=eval(dp[j][k].front(),i)) continue;
					else{
                        dp[j][k].push_front(fs);
                        break;
					}
				}
            }
		}
	}
	int ans = 0;
	for(k=0;k<=N*(N-1)/2;k++){
		while(dp[0][k].size()>=2){
            pii fs = dp[0][k].front(); dp[0][k].pop_front();
			if(eval(fs,0)>=eval(dp[0][k].front(),0)) continue;
			else{
                dp[0][k].push_front(fs);
                break;
			}
		}
		if(dp[0][k].size()) ans = max(ans, (N-K)*(N-K-1)/2-eval(dp[0][k].front(),0));
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}