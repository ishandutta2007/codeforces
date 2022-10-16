#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	int max = 1,j = 1; 
   for (int i = 1; i < n; i++) { 
            if (A[i] >= A[i - 1]){
                j++; 
            }
            else 
            {  
                if (max < j){
                    max = j;
                }
                j = 1; 
            }
        }
        if (max < j){ 
            max = j;
           }
        printf("%d",max);
        }