#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int as[]={1,2,3,4,6,12};
int bs[]={12,6,4,3,2,1};

char ch[20];
bool check(int a,int b){
	for(int j=0;j<b;j++){
		bool ok=true;
		for(int id=j;id<12;id+=b){
			if(ch[id]!='X') ok=false;
		}
		if(ok) return true;
	}
	return false;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		vector<int> anss;
		scanf("%s",ch);
		for(int i=0;i<6;i++){
			bool flg=check(as[i],bs[i]);
			if(flg) anss.push_back(as[i]);
		}
		printf("%d",(int)anss.size());
		for(int i=0;i<anss.size();i++){
			int a=anss[i];
			int b=12/a;
			printf(" %dx%d",a,b);
		}
		printf("\n");
	}
	return 0;
}