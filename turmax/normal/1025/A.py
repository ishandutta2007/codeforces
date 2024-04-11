n=int(input())
s=str(input())
if(n==1):
    print("YES")
else:
    m=[str(i) for i in s]
    if(len(set(m))==n):
        print("NO")
    else:
        print("YES")