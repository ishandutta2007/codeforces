#include <bits/stdc++.h>
using namespace std;
const int N=100050;
char s[N],t[N];
int kmp[N],fir[N],len[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)t[i]=s[i];
	reverse(s+1,s+1+n);
	kmp[0]=kmp[1]=0;
	for(int i=2;i<=n;i++){
		int j=kmp[i-1];
		while(j && s[i]!=s[j+1])j=kmp[j];
		if(j<n && s[i]==s[j+1])j++;
		kmp[i]=j;
	}
	int mx=0;
	for(int i=1,j=0;i<=n;i++){
		while(j && t[i]!=s[j+1])j=kmp[j];
		if(j<n && t[i]==s[j+1])j++;
		if(!fir[j])fir[j]=i;
		mx=max(mx,j);
	}
	fir[0]=0;
	auto Manacher=[&](int L,int R){
		pair<int,int> mx={0,0};
		for(int i=L,l=0,r=-1;i<=R;i++){
			if(r>=i)len[i]=min(len[l+r-i],r-i+1);
			else len[i]=0;
			while(i-len[i]>=L && i+len[i]<=R && t[i+len[i]]==t[i-len[i]])len[i]++;
			if(i+len[i]-1>r)l=i-len[i]+1,r=i+len[i]-1;
			mx=max(mx,{len[i]*2-1,i-len[i]+1});
		}
		return mx;
	};
	int ans=0,ssz;
	Manacher(1,n);
	for(int i=1;i<=n;i++){
		int top=mx,bot=0,mid,idx;
		while(top>=bot){
			mid=top+bot>>1;
			if(i+len[i]-1<n-mid+1 && fir[mid]<i-len[i]+1)bot=mid+1,idx=mid;
			else top=mid-1;
		}
		int now=idx*2+len[i]*2-1;
		if(now>ans)ans=now,ssz=idx;
	}
	if(ssz==0){
		printf("1\n");
		pair<int,int> A=Manacher(1,n);
		printf("%i %i\n",A.second,A.first);
	}else{
		printf("3\n");
		printf("%i %i\n",fir[ssz]-ssz+1,ssz);
		pair<int,int> A=Manacher(fir[ssz]+1,n-ssz);
		printf("%i %i\n",A.second,A.first);
		printf("%i %i\n",n-ssz+1,ssz);
	}
	return 0;
}