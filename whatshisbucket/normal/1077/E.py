n=int(input())
a=list(map(int,input().split()))
counts={}
for guy in a:
    if guy in counts:
        counts[guy]+=1
    else:
        counts[guy]=1
clist=[counts[guy] for guy in counts]
clist.sort(reverse=True)
bylen=[clist[0]]
curr=clist[0]
for i in range(len(clist)-1):
    curr=min(clist[i+1],curr//2)
    bylen.append(curr*(2**(i+2)-1))
    if curr==0:
        break
print(max(bylen))