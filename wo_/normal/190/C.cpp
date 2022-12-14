#include<cstdio>
#include<stack>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

stack<int> st;

bool which[100100];//pair:true,int:false;

void outputError()
{
	printf("Error occurred\n");
	exit(0);
}

string ans;

int main()
{
	int a;
	scanf("%d",&a);/*
	for(int i=0;i<N;i++)
	{
		char ch[100];
		scanf("%s",ch);
		if(ch[0]=='p') which[i]=true;
		else which[i]=false;
	}*/
	int N=0;
	char ch[10];
	while(~scanf("%s",ch))
	{
		if(ch[0]=='p') which[N]=true;
		else which[N]=false;
		N++;
	}
	if(which[0]==false)
	{
		if(N==1)
		{
			printf("int\n");
			return 0;
		}
		else outputError();
	}
	st.push(1);
	ans="pair<";
	for(int i=1;i<N;i++)
	{
		if(st.size()==0) outputError();
		if(which[i]==true)
		{
			if(ans[ans.size()-1]=='<') ans+="pair<";
			else ans+=",pair<";
			st.push(1);
		}
		else
		{
			if(ans[ans.size()-1]=='t'||ans[ans.size()-1]=='>') ans+=",";
			ans+="int";
			while(!st.empty()&&st.top()==2)
			{
				ans+=">";
				st.pop();
			}
			if(i==N-1) break;
			if(i!=N-1&&st.size()==0) outputError();
			st.top()++;
		}
	}
	if(st.size()!=0) outputError();
	cout<<ans<<"\n";
	return 0;
}