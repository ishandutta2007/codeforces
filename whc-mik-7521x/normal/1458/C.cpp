#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t,n,m,mp[N][N],mp2[N][N],dx,dy,dz,pd,ct;
char s[100005];
int main(){
	scanf("%d",&t);
	while(t--){
		dx=dy=dz=ct=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int o=0;o<n;o++){
				scanf("%d",&mp[i][o]);
				mp[i][o]--;
			}
		}
		scanf("%s",s+1);
		for(int i=1;i<=m;i++){
			if(s[i]=='U')dx=(dx-1+n)%n;
			if(s[i]=='D')dx=(dx+1)%n;
			if(s[i]=='L')dy=(dy-1+n)%n;
			if(s[i]=='R')dy=(dy+1)%n;
			if(s[i]=='I'){
				swap(dy,dz);
				if(!ct)ct=1,pd=0;
				else (ct&1)^pd?ct--:ct++;
			}
			if(s[i]=='C'){
				swap(dx,dz);
				if(!ct)ct=1,pd=1;
				else (ct&1)^pd?ct++:ct--;
			}
		}
		ct%=6;
		for(int k=1,kk=pd;k<=ct;k++,kk^=1){
			if(kk==0){
				for(int i=0;i<n;i++){
					for(int o=0;o<n;o++){
						mp2[i][mp[i][o]]=o;
                    }
                }
            }
			else{
				for(int i=0;i<n;i++){
					for(int o=0;o<n;o++){
						mp2[mp[i][o]][o]=i;
                    }
                }
            }
			for(int i=0;i<n;i++){
				for(int o=0;o<n;o++){
					mp[i][o]=mp2[i][o];
                }
            }
		}
		for(int i=0;i<n;i++){
			for(int o=0;o<n;o++){
				printf("%d ",(mp[(i-dx+n)%n][(o-dy+n)%n]+dz)%n+1);
            }
            puts("");
        }
	}
	return 0;
} //