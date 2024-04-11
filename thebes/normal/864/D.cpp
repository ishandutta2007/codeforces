#include <bits/stdc++.h>
using namespace std;

int cnt[200002], tk[200002], out[200002], N, ans, i, j;
vector<int> f;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&out[i]); cnt[out[i]]++;
	}
	for(i=1;i<=N;i++){
		if(!cnt[i]) f.push_back(i);
	}
	for(i=1,j=0;i<=N;i++){
		if(cnt[out[i]]--){
			if(tk[out[i]]){
				out[i] = f[j++];
				ans++;
			}
			else{
				if(j!=f.size() && cnt[out[i]]){
					if(f[j] > out[i]) tk[out[i]] = 1;
					else{out[i] = f[j++]; ans++;}
				}
				else tk[out[i]] = 1;
			}
		}
	}
	for(printf("%d\n",ans),i=1;i<=N;i++)
		printf("%d ",out[i]);
	return 0;
}