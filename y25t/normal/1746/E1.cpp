#include<bits/stdc++.h>

char res[10];
inline bool qry(std::vector<int> V){
	printf("? %d ",(int)V.size());
	for(auto x:V)
		printf("%d ",x);
	puts(""),fflush(stdout);
	scanf("%s",res);
	return res[0]=='Y';
}
inline bool gss(int x){
	printf("! %d\n",x),fflush(stdout);
	scanf("%s",res);
	return res[1]==')';
}

inline void uni(std::vector<int> &V,std::vector<int> &A,std::vector<int> &B){
	std::swap(V,A);
	for(auto x:B)
		V.emplace_back(x);
}

int n;

int main(){
	scanf("%d",&n);
	if(n==1)
		return gss(1),0;
	if(n==2){
		if(!gss(1))
			gss(2);
		return 0;
	}
	std::vector<int> V(n);
	std::iota(V.begin(),V.end(),1);
	while(V.size()>2){
		int l=V.size()/3,L=((int)V.size()-l)/2;
		std::vector<int> A(V.begin(),V.begin()+l),B(V.begin()+l,V.begin()+l+L),C(V.begin()+l+L,V.end());
//		puts("---");
//		for(auto i:V)
//			printf("%d ",i);
//		puts("");
//		for(auto i:A)
//			printf("%d ",i);
//		puts("");
//		for(auto i:B)
//			printf("%d ",i);
//		puts("");
//		for(auto i:C)
//			printf("%d ",i);
//		puts("");
		int x=qry(A);
		if(x){
			int y=qry(B);
			if(y)
				uni(V,A,B);
			else
				uni(V,A,C);
		}
		else{
			int y=qry(A);
			if(!y)
				uni(V,B,C);
			else{
				int z=qry(B);
				if(z)
					uni(V,A,B);
				else
					uni(V,A,C);
			}
		}
	}
	if(V.size()==1){
		gss(V[0]);
		return 0;
	}
	if(V.size()==2){
		if(!gss(V[0]))
			gss(V[1]);
		return 0;
	}
	int x=V[0],y=V[1],z=V[2];
	if(qry(std::vector<int>({x}))){
		if(!gss(x))
			assert(gss(qry(std::vector<int>({y}))?y:z));
	}
	else{
		if(qry(std::vector<int>({y}))){
			if(!gss(y))
				assert(gss(z));
		}
		else if(!gss(z))
			assert(gss(x));
	}
}