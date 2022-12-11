import math
s="*"
s=s+input()
s=s+"*"
n=len(s)
ans=0
for i in range(0,n):
    if s[i]=='*':
        for j in range(i+1,n-1):
            if s[j+1]=='*':
                a=""
                for k in range(0,n-1):
                    if k>0:
                        a=a+s[k]
                    if k==i:
                        a=a+"("
                    if k==j:
                        a=a+")"
                t=eval(a)
                if t>ans:
                    ans=t
print(ans)