#include <bits/stdc++.h>
using namespace std;
const int N=105;
int r[N],ord[N];
void Dec(int i){if(r[i]>0)r[i]--;}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&r[i]),ord[i]=i;
	vector<string> ans;
	while(1){
		bool eq=true;
		for(int i=1;i<=n;i++)if(r[i]!=r[1])eq=false;
		if(eq)break;
		sort(ord+1,ord+1+n,[&](int i,int j){return r[i]>r[j];});
		if(n>3&&r[ord[n]]+1==r[ord[1]]&&r[ord[3]]==r[ord[1]]&&r[ord[4]]==r[ord[n]]){
			Dec(ord[1]);
			Dec(ord[2]);
			Dec(ord[3]);
			string str="";
			for(int i=1;i<=n;i++){
				if(i==ord[1]||i==ord[2]||i==ord[3])str+='1';
				else str+='0';
			}
			ans.push_back(str);
		}else{
			Dec(ord[1]);
			Dec(ord[2]);
			string str="";
			for(int i=1;i<=n;i++){
				if(i==ord[1]||i==ord[2])str+='1';
				else str+='0';
			}
			ans.push_back(str);
		}
	}
	printf("%i\n",r[1]);
	printf("%i\n",ans.size());
	for(string s:ans)printf("%s\n",s.c_str());
	return 0;
}