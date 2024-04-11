#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;
char a[maxn],b[maxn];
int line[maxn],len1,len2;
bool vis[maxn];
bool Judge(){
	int pos=0;
	for(int i=0;i<len1;i++){
		if(vis[i])continue;
		if(a[i]==b[pos])
			pos++;
		if(pos==len2)return true;
	}
	return false;
}
int work(int l,int r){
	int mid=((r-l)>>1)+l;
	if(Judge()){
		for(int i=mid+1;i<=((r-mid-1)>>1)+mid+1;i++)
			vis[line[i]]=true;
		if(mid+1!=r)return work(mid+1,r);
		if(Judge())return r;
		return r-1;
	}
	else{
		for(int i=((mid-l)>>1)+l+1;i<=mid;i++)
			vis[line[i]]=false;
		if(l!=mid)return work(l,mid);
		return l-1;
	}
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%s\n%s",a,b);
	len1=strlen(a),len2=strlen(b);
	for(int i=0;i<len1;i++){
		scanf("%d",&line[i]);
		line[i]--;
	}
	for(int i=0;i<=len1/2;i++){
		vis[line[i]]=true;
	}
	int ans=work(0,len1);
	printf("%d",ans+1);
	return 0;
}