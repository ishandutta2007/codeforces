#include<cstdio>
#include<algorithm>
#include<vector>

int n,k;

int ans;
inline void qry(){
	static int x;
	scanf("%d",&x);
	ans^=x;
}

int main(){
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	if(!(k&1)&&(n&1)){
		puts("-1");
		fflush(stdout);
		return 0;
	}
	int d=n%k;
	if(!d){
		for(int l=d+1,r=d+k;l<=n;l+=k,r+=k){
			printf("?");
			for(int i=l;i<=r;i++)
				printf(" %d",i);
			puts("");
			fflush(stdout);
			qry();
		}
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	if(!((k+d)&1)&&n>2*k){
		for(int l=k+d+1,r=k+d+k;l<=n;l+=k,r+=k){
			printf("?");
			for(int i=l;i<=r;i++)
				printf(" %d",i);
			puts("");
			fflush(stdout);
			qry();
		}
		printf("?");
		for(int i=1;i<=(d+k)/2;i++)
			printf(" %d",i);
		for(int i=k+d+1;i<=k+d+k-(d+k)/2;i++)
			printf(" %d",i);
		puts("");
		fflush(stdout);
		qry();
		printf("?");
		for(int i=(d+k)/2+1;i<=(d+k)/2+k;i++)
			printf(" %d",i);
		puts("");
		fflush(stdout);
		qry();
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	if(!(d&1)){
		for(int l=d+1,r=d+k;l<=n;l+=k,r+=k){
			printf("?");
			for(int i=l;i<=r;i++)
				printf(" %d",i);
			puts("");
			fflush(stdout);
			qry();
		}
		printf("?");
		for(int i=1;i<=d/2;i++)
			printf(" %d",i);
		for(int i=d+1;i<=d+k-d/2;i++)
			printf(" %d",i);
		puts("");
		fflush(stdout);
		qry();
		printf("?");
		for(int i=d/2+1;i<=d/2+k;i++)
			printf(" %d",i);
		puts("");
		fflush(stdout);
		qry();
	}
	else{
		std::vector<int> A,B;
		for(int i=1;i<=n;i++)
			A.push_back(i);
		while(B.size()+A.size()/2<k){
			printf("?");
			for(int i=d;i<A.size();i++)
				printf(" %d",A[i]);
			for(auto i:B)
				printf(" %d",i);
			puts("");
			fflush(stdout);
			qry();
			printf("?");
			for(int i=0;i<d;i++)
				printf(" %d",A[i]);
			for(int i=d+d;i<A.size();i++)
				printf(" %d",A[i]);
			for(auto i:B)
				printf(" %d",i);
			puts("");
			fflush(stdout);
			qry();
			std::vector<int> tmp;
			for(int i=0;i<d+d;i++)
				B.push_back(A[i]);
			for(int i=d+d;i<A.size();i++)
				tmp.push_back(A[i]);
			A=tmp;
		}
		printf("?");
		for(int i=0;i<A.size()/2;i++)
			printf(" %d",A[i]);
		for(int i=0;i<k-A.size()/2;i++)
			printf(" %d",B[i]);
		puts("");
		fflush(stdout);
		qry();
		printf("?");
		for(int i=A.size()/2;i<A.size();i++)
			printf(" %d",A[i]);
		for(int i=0;i<k-A.size()/2;i++)
			printf(" %d",B[i]);
		puts("");
		fflush(stdout);
		qry();
	}
	printf("! %d\n",ans);
	fflush(stdout);
}