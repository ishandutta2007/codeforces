#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
        multiset<long long>st,que;
		scanf("%d",&n);
        long long sum=0;
		for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            sum+=x;
            st.insert(x);
        }
		bool pd=1;
		que.insert(sum);
		while(!que.empty()){
			long long u=(*--que.end());
            que.erase(que.find(u));
            long long v=*(--st.end());
			if(v>u){pd=0;break;}
			if(v==u){
				st.erase(st.find(v));
			}
            else{
                if(*st.begin()>sum){pd=0;break;}
                que.insert(u>>1),que.insert((u+1)>>1);
            }
		}
		puts(pd?"YES":"NO");
	}
	return 0;
}