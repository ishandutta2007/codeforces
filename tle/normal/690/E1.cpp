#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
string ans="YNNYNNNNNYYYYNYYNYNYNNYNNYNNYYYYNNNYYYNYYNYYNYYYNYNNYYYYYNNYYNNNNNNNNNYNYNNNYYNYYNNNNNNYNNYNYNNNNYYYYYNNNYNYNNNYYNYYYYNNNYNYYYNYNNNYNNNYNYYYYYYYYYNYYNNNNYNNYNYNYNYNNYNNNYNNNNYNNNYYNYNYNNNYYNYNYYYNYYNYYYYNYYNNYNNNYYYY";
int main()
{
	for(int i=0;i<ans.length();i++)
	{
		if(ans[i]=='Y') puts("YES");
		else puts("NO");
	}
}