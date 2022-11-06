n=int(raw_input())
nbt=2**n
p=[0]*nbt
for i in range(nbt):
    p[i]=[int(k) for k in raw_input().split(" ")]
pbase=1

#proba de chaque mec de gagner le xieme round
pr=[0]*(n+1)
ts=[0]*(n+1)
pr[0]=[pbase]*nbt
ts[0]=[0]*nbt
#print pr[0]
for k in range(1,n+1):
    nbo=2**k
    pr[k]=[0]*nbt
    ts[k]=[j for j in ts[k-1]]
    for i in range(nbt):
        if i%(nbo/2)==0:
            omin=i+nbo/2 if i%nbo==0 else i-nbo/2            
            opps=range(i+nbo/2,i+nbo) if i%nbo==0 else range(i-nbo/2,i)
            popps=pr[k-1][omin:omin+nbo/2]
        for j in range(len(opps)):
            pr[k][i]+=p[i][opps[j]]*popps[j]/100.0
        pr[k][i]*=pr[k-1][i]
        pr[k][i]/=pbase
        ts[k][i]+=pr[k][i]*nbo/2
        ts[k][i]+=max([ts[k-1][j] for j in opps])
#    print pr[k]
# print pr    
# print ts
##OK now je redescends...
#winners=None
#for i in range(n,0,-1):
#    if winners is None:
#        currmax=-1
#        currbest=-1
#        for k in range(nbt):
#            if ts[i][k]>currmax:
#                currmax=ts[i][k]
#                currbest=k
#        winners=[currbest]
#        res+=ts[i][currbest]
# #       print res
#    else:
#        nbo=2**(i+1)
#        for w in [j for j in winners]:
#            opps=range((w/nbo)*nbo+nbo/2,(w/nbo)*nbo+nbo) if w%nbo<nbo/2 else range((w/nbo)*nbo,(w/nbo)*nbo+nbo/2)
#            currmax=-1
#            currbest=-1
#            for k in opps:
#                if ts[i][k]>currmax:
#                    currmax=ts[i][k]
#                    currbest=k
#            winners+=[currbest]
#            res+=ts[i][currbest]

print max(ts[-1])