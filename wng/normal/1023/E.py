n=int(raw_input())

wia=(1,1)
togo=(n,n)

path=[]
pcol=[wia]
import sys

while sum(wia)<n+1:
    print "? {} {} {} {}".format(wia[0]+1,wia[1],n,n)
    sys.stdout.flush()
    rep=raw_input()
    assert(rep[0]!="B")
    if rep[0]=="Y":
        wia=(wia[0]+1,wia[1])
        path+=["D"]
    else:
        wia=(wia[0],wia[1]+1)
        path+=["R"]
    pcol+=[wia]

#OK G atteint la moitie, je refais la meme en partant de la fin

path2=[]
pcol2=[togo]
k=-2
while sum(togo)>n+2:
   #print togo, pcol[k]
    if togo[0]>pcol[-1][0]:
        print "? {} {} {} {}".format(pcol[k][0],pcol[k][1],togo[0],togo[1]-1)
        sys.stdout.flush()
        rep=raw_input()
        assert(rep[0]!="B")
        if rep[0]=="Y":
            togo=(togo[0],togo[1]-1)
            path2+=["R"]
        else:
            togo=(togo[0]-1,togo[1])
            path2+=["D"]
    else:
        togo=(togo[0],togo[1]-1)
        path2+=["R"]
    pcol2+=[togo]
    if k<len(pcol):
        k-=1       

miyeu= "D" if togo[0]==pcol[-1][0]+1   else "R"

assert(abs(togo[0]-pcol[-1][0])+abs(togo[1]-pcol[-1][1])==1)

##res=pcol[:-1]+pcol2[::-1]
##for k in range(2):
##    print "? {} {} {} {}".format(res[k][0],res[k][1],res[k+n-1][0],res[k+n-1][1])
##    sys.stdout.flush()
##    rep=raw_input()
##    assert(rep[0]=="Y")
    
        
print "! {}".format("".join(path+[miyeu]+path2[::-1]))