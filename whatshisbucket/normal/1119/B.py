n,h=map(int,input().split())
a=list(map(int,input().split()))
used=[]
don=False
for i in range(n):
    if used==[]:
        used.append(a[i])
    else:
        done=False
        for j in range(i):
            if a[i]<used[j]:
                used=used[:j]+[a[i]]+used[j:]
                done=True
                break
        if not done:
            used.append(a[i])
    if sum(used[-1::-2])>h:
        print(i)
        don=True
        break
if not don:
    print(n)