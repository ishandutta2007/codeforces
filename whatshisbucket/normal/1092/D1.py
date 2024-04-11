n=int(input())
a=list(map(int,input().split()))
b=0
for i in range(n):
    if a[i]%2==1:
        if i%2==0:
            b+=1
        else:
            b-=1
if n%2==0:
    if b==0:
        print("YES")
    else:
        print("NO")
else:
    if b==0 or b==1:
        print("YES")
    else:
        print("NO")