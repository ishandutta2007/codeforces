#[int(k) for k in raw_input().split(" ")]


##for i in range(1,11):
##    poss=set()
##    for a in range(i+1):
##        for b in range(i+1-a):
##            for c in range(i+1-a-b):
##                poss.add(i+a*49+b*9+c*4)
##    print poss if i<=4 else None,len(poss)


#En combien de 0,4 et 9 je peux faire mon plus petit k mod 49:

res=[10000]*49
for i in range(49):
    for j in range(49):
        res[(4*i+9*j)%49]=min(res[(4*i+9*j)%49],i+j)

#print res

#for n in range(1,11):
if True:
    n=int(raw_input())
    rr=0
    for i in res:
        rr+=max(0,n-i+1)
    print rr