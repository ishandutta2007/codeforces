#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;

char ch[100100];

stack<char> st;

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	for(int i=0;i<N;i++)
	{
		if(!st.empty()&&st.top()==ch[i]) st.pop();
		else st.push(ch[i]);
	}
	if(st.empty()) printf("Yes\n");
	else printf("No\n");
	return 0;
}