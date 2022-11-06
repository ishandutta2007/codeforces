s=raw_input()
n=len(s)
res=0
isok=False
wf="["
i=0
minfirst=1000000
for k in s:
    if not isok:
        if k==wf:
            if wf=="[":
                wf=":"
            else:
                isok=True
                minfirst=i+1
        else:
            res+=1
    else:
        break
    i+=1
   
maxlast=0
wf="]"
i=n-1
isok=False
for k in s[::-1]:
    if not isok:
        if k==wf:
            if wf=="]":
                wf=":"
            else:
                isok=True
                maxlast=i
        else:
            res+=1
    else:
        break
    i-=1

if minfirst<=maxlast:
    print 4+len([k for k in s[minfirst:maxlast] if k=="|"])
else:
    print -1