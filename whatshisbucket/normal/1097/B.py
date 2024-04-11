n=int(input())
v=[0]*n
for i in range(n):
    v[i]=int(input())
done=False
for i in range(2**(n-1)):
    a=bin(i)[:1:-1]
    a+="0"*(n-1-len(a))
    sumi=v[-1]
    for i in range(n-1):
        if a[i]=="1":
            sumi+=v[i]
        else:
            sumi-=v[i]
    if sumi%360==0:
        print("YES")
        done=True
        break
if not done:
    print("NO")