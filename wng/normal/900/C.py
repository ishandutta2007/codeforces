
n=int(raw_input())
t=[int(k) for k in raw_input().split(" ")]

rim1=0
ri=0

i=0
recadd=0
mr=-1
bestremove=0
cfr=0
nonrec=set(range(1,n+1))
if n<=2:
    print 1
else:
    while i<n:
        if t[i]>ri:
            nonrec.discard(t[i])
            rim1,ri=ri,t[i]
            if (recadd>mr) and rim1>0:
                mr=recadd
                bestremove=rim1
            cfr=rim1
            recadd=0
       #     print "yup"
        elif t[i]>cfr:
            recadd+=1
            cfr=t[i]
      #  print t[i],rim1,recadd,mr,bestremove,cfr
        i+=1
    if recadd>mr:
        mr=recadd
        bestremove=ri
    if mr>1:
        print bestremove
    else:
        print min(nonrec) if len(nonrec)>0 else 1