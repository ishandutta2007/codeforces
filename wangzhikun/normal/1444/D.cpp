#include<bits/stdc++.h>
using namespace std;typedef vector<int>V;const int N=1005,U=1e6+5;bitset<U>b[N];int T,n,i,j,a[N];V v1,v2,v3,v4;bool FL;
inline void input(V&v1,V&v2){v1.clear();v2.clear();scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);random_shuffle(a+1,a+n+1);for(i=0;i<=n;++i)b[i].reset();
b[0][U/2]=1;for(i=1;i<=n;++i)b[i]=(b[i-1]<<a[i])|(b[i-1]>>a[i]);if(!b[n][U/2]){FL=0;return;}
	for(i=n,j=U/2;i;--i)if(0<=j-a[i] && j-a[i]<U && b[i-1][j-a[i]])j-=a[i],v1.push_back(a[i]);else j+=a[i],v2.push_back(a[i]);if(v1.size()>v2.size())swap(v1,v2);}
int main(){srand(114514);for(scanf("%d",&T);T--;){FL=1;input(v1,v2);input(v3,v4);if(v1.size()+v2.size()!=v3.size()+v4.size())FL=0;if(!FL){puts("No");continue;}
		sort(v1.begin(),v1.end(),greater<int>());sort(v2.begin(),v2.end(),greater<int>());sort(v3.begin(),v3.end());sort(v4.begin(),v4.end());
		puts("Yes");int x=0,y=0;for(i=0;i<v1.size();++i){printf("%d %d\n",x+=v1[i],y);printf("%d %d\n",x,y+=v4[i]);}
		for(j=0;i<v4.size();++i,++j){printf("%d %d\n",x-=v2[j],y);printf("%d %d\n",x,y+=v4[i]);}
        for(i=0;j<v2.size();++j,++i){printf("%d %d\n",x-=v2[j],y);printf("%d %d\n",x,y-=v3[i]);}}}