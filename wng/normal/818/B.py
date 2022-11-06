n,m=[int(i) for i in raw_input().split(" ")]
l=[int(i) for i in raw_input().split(" ")]

poss=True
perms=[0]*n
left = dict(zip(range(1,n+1),[0]*n))

for i in range(m-1):
    ta=(l[i+1]-l[i]-1)%n+1
 #  print i,ta,perms,l[i]
    if (perms[l[i]-1]==0 and ta in left):
        perms[l[i]-1]=ta
        del left[ta]
    elif perms[l[i]-1]!=ta:
        poss=False

left=[k for k in range(1,n+1) if k not in perms]

la=0
for i in range(n):
    if perms[i]==0:
        perms[i]=left[la]
        la+=1

print " ".join([str(k) for k in perms]) if poss else -1