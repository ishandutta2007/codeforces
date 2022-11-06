n,m=[int(ii) for ii in raw_input().split(" ")]


dc={} #all child must be after
dp={}
dpc={}

global dm
dm=set()

ow=[int(ii) for ii in raw_input().split(" ")[1:]]
  
stillok=True
for i in range(1,n):
    nw=[int(ii) for ii in raw_input().split(" ")[1:]]
    ok=False
    for j in range(len(nw)):
        if nw[j]!=ow[j]:
            if ow[j] not in dc:
                dc[ow[j]]=set()
            dc[ow[j]].add(nw[j])
            if nw[j] not in dp:
                dp[nw[j]]=set()
                dpc[nw[j]]=set()
            dp[nw[j]].add(ow[j])
            dpc[nw[j]].add(ow[j])
            ok = True
            break
        if j==len(ow)-1:
            ok=True
            break
    if not ok:
        stillok=False
    ow=nw

#Actually I'll do two things : 
# 1. Check that the graph has no cycle
# 2. Go from the bottom of the graph to the top and making sure I can do this without 2 guys
#For this will need nodes without predecessors and nodes without followers
cl=set(dp)-set(dc)
pl=set(dc)-set(dp)
#let's make a topological sort, right?
ts=[]
while len(pl)!=0:
    elem=pl.pop()
    ts+=[elem]
    if elem in dc:
        for ce in dc[elem]:
            dpc[ce].discard(elem)
            if len(dpc[ce])==0:
                pl.add(ce)
                del dpc[ce]
if len(dpc)>0: #CYCLE DETECTED !!!
    print "No"
    s1="No"
else:
    #Step 2 : let's empty cl ...
    while len(cl)!=0:
        elem=cl.pop()
        if elem in dp:
            for pe in dp[elem]:
                if pe > elem:
                    if elem in dm:
                        stillok=False
                        cl=set()
                    else:                    
                        dm.add(pe)                    
                elif elem in dm:
                    dm.add(pe)
                dc[pe].discard(elem)
                if len(dc[pe])==0:
                    del dc[pe]
                    cl.add(pe)
    if not stillok:
        print "No"
        s1="No"
    else:
        print "Yes"
        print len(dm)
        print " ".join([str(k) for k in dm])
        s1="Yes"
        
        
        
        
        
        
#
##Then I'm allowed 1 and only 1 retour a zero
#rr=1
#
#def addm(k):
#    global dm
#    if k not in dm:
#        dm.add(k)
#        if k in dp:
#            for kk in dp[k]:
#                addm(kk)
#
##sk=sorted(dc.keys())
#for k in dc.keys():
#    if k not in dm:
#        tocap=False
#        for j in dc[k]:
#            if j<k:
#                tocap=True
#                break
#        if tocap:
#            dm.add(k)
#            while k in dp:
#                if dp[k]>k:
#                    stillok=False
#                    break
#                else:
#                    dm.add[dp[k]]
#                    k=dp[k]
#        if not stillok:
#            break
#            
#                
#if stillok:
#    print "Yes"
#    print len(dm)
#    print " ".join([str(k) for k in list(dm)])
#else:
#    print "No"