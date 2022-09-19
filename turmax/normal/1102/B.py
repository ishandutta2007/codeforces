n,k=map(int,input().split())
a=list(map(int,input().split()))
l=[-1 for i in range(n)]
if(len(a)<k):
    print("NO")
    exit(0)
v={}
for i in range(n):
    try:
        v[a[i]].append(i)
    except:
        v[a[i]]=[i]
b=set(a)
f1=0
for i in b:
    p=v[i]
    if(len(p)>k):
        print("NO")
        exit(0)
    for o in range(k):
        try:
            l[p[o]]=((f1)%k)
            f1+=1
        except:
            break
    f1%=k
print("YES")
for i in range(n):
    print(l[i]+1,end=" ")