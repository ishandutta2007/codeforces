n,m=[int(k) for k in raw_input().split(" ")]
p=[int(k) for k in raw_input().split(" ")]

from sys import stdout

op=[-1]*(2*n)
ptc=[]
for i in range(m):
    a,b=[int(k) for k in raw_input().split(" ")]
    op[a-1]=b-1
    op[b-1]=a-1
    if p[a-1]>p[b-1]:
        ptc+=[a-1]
    else:
        ptc+=[b-1]

t=[int(k) for k in raw_input().split(" ")][0]
nonspe=[k for k in range(2*n) if op[k]==-1]
nonspe=sorted(nonspe,key=lambda x:p[x],reverse=True)

done=[0]*(2*n)
indnonspe=0
nbd=0
if t==1:
    for kk in range(len(ptc)):
        print ptc[kk]+1
        stdout.flush()
        answ=[int(k) for k in raw_input().split(" ")][0]
        assert answ-1==op[ptc[kk]]
        done[ptc[kk]]=1
        done[op[ptc[kk]]]=1
        nbd+=2
    while nbd<2*n:
        while done[nonspe[indnonspe]]:
            indnonspe+=1
        print nonspe[indnonspe]+1
        stdout.flush()
        answ=[int(k) for k in raw_input().split(" ")][0]
        done[answ-1]=1
        done[nonspe[indnonspe]]=1
        nbd+=2
else:
    indspe=0
    fp=[int(k) for k in raw_input().split(" ")][0]
    fp-=1
    while op[fp]!=-1:
        print op[fp]+1
        stdout.flush()
        done[fp]=1
        done[op[fp]]=1
        nbd+=2
        if nbd==2*n:
            break
        fp=[int(k) for k in raw_input().split(" ")][0]-1
    done[fp]=1
    while nbd<2*n:
        if indspe<len(ptc):
            while indspe<len(ptc) and done[ptc[indspe]]:
                indspe+=1
            if indspe<len(ptc):
                print ptc[indspe]+1
                stdout.flush()
                nbd+=2
                if nbd>=2*n:
                    break
                answ=[int(k) for k in raw_input().split(" ")][0]
                assert answ-1==op[ptc[indspe]]
                done[ptc[indspe]]=1
                done[op[ptc[indspe]]]=1
                indspe+=1
        else:
            while done[nonspe[indnonspe]]:
                indnonspe+=1
            print nonspe[indnonspe]+1
            stdout.flush()
            nbd+=2
            if nbd>=2*n:
                break
            answ=[int(k) for k in raw_input().split(" ")][0]
            done[answ-1]=1
            done[nonspe[indnonspe]]=1