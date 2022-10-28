import math
n,m,k,l=map(int,input().split())
if m>n:
    print(-1)
elif l==0:
    print(0)
else:
    per=math.ceil((k+l)//m)
    if not (k+l)%m==0:
        per+=1
    if per*m>n:
        print(-1)
    else:
        print(per)