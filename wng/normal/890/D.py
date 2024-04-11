n=int(raw_input())
t=[0]*n
for k in range(n):
    t[k]=raw_input()

dl={}    
df=range(n) 
ok=True
tomerge=[]
k=0
dw={}

while k<n:
    tk=t[k]
    assignto=k
    mw=[]
    merged=False
    for i in range(len(tk)):
        l=tk[i]
      #  print l, l in dl
        if l not in dl:
            dl[l]=[(k,i)]
        else:
            if dl[l][0][0]==k:
                ok=False
            else:
                merged=True
                #let's merge tk with t[dl[l][0][0]]
                i=dl[l][0][0]
                if tk in t[i]:
                    nw=t[i]
                elif t[i] in tk:
                    nw=tk
                else:
                    nw=""
                    #ok so one word should contain in the end the beginning of another
                    if tk[0] in t[i]:
                        k1=0
                        while t[i][k1]!=tk[0]:
                            nw+=t[i][k1]
                            k1+=1
                        nw+=tk
                    elif t[i][0] in tk:
                        k1=0
                        while tk[k1]!=t[i][0]:
                            nw+=tk[k1]
                            k1+=1
                        nw+=t[i]
                del dw[i]
                if t[i] in nw and tk in nw:
                    for j in range(len(nw)):
                        if nw[j] in dl:
                           # print i,k,nw[j],dl[nw[j]][0][0],dl[nw[j]][0][0] in (k,i)
                            if dl[nw[j]][0][0] in (k,i):
                                del dl[nw[j]]
                          #  print dl
                    t[k]=nw
                else:
                    ok=False
                break
    if not merged:
        dw[k]=tk        
        k+=1
    if not ok:
        break
        
if not ok:
    print "NO"
else:
    st=sorted(dw.values())
    res=""
    for k in st:
        res+=k
    print res