n=int(input())
a=list(map(int,input().split()))
counts=[0]*n
done=False
for i in range(n):
    counts[a[i]]+=1
for i in range(n):
    if counts[i]%(n-i)!=0:
        print("Impossible")
        done=True
        break
    else:
        counts[i]//=(n-i)
countsum=[counts[0]]
for i in range(n-1):
    countsum.append(countsum[-1]+counts[i+1])
b=[]
seen=[0]*n
for i in range(n):
    b.append(countsum[a[i]]-seen[a[i]]//(n-a[i]))
    seen[a[i]]+=1
out=""
for i in range(n):
    out+=str(b[i])+" "
if not done:
    print("Possible")
    print(out[:-1])