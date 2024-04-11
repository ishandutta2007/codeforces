#include <iostream>
#include <string>
using namespace std;
int main()
{
        string s;
        while(cin>>s)
		{
                int max1=0;
                for(int i=0;i<s.size();i++){
                	for(int j=i+1;j<s.size();j++)
						{
                            int conti=0;
                            for(;;)
							{
								if(s[i+conti]==s[j+conti] )
									{
                             	   	   conti++;
                            	    }
                            	else
                            		break;
                                max1=max(conti,max1);
							}
                        }
                }
                cout<<max1;
        }
        return 0;
}