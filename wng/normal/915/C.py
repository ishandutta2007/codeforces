a=raw_input()
b=raw_input()

da=sorted(a)


if len(a)<len(b):
    print "".join(sorted(a,reverse=True))
else:
    bestlower=""
    besteq=""
    kmax=0
    arewestilltrying=True
    while len(da)>0 and arewestilltrying:
        toget=b[len(b)-len(da)]
        k=0
        bl=-1
        e=-1
        for k in range(len(da)):
            if da[k]<toget:
                bl=k
            elif da[k]==toget:
                e=k
                break
            else:
                break
        if bl<0 and e<0:
            break
        elif bl>=0:
            bestlower=besteq+da[bl]+"".join(sorted(da[:bl]+da[bl+1:],reverse=True))
        if arewestilltrying:
            if e<0:
                arewestilltrying=False
                break
            else:
       #         print "".join(sorted(da[:e]+da[e+1:])),b[len(besteq)+1:]
                if "".join(sorted(da[:e]+da[e+1:]))<=b[len(besteq)+1:]:
                    #c OK pour l'eq
                    besteq+=da[e]
                    da=da[:e]+da[e+1:]
                    bestlower=besteq+"".join(da)
                else:
                    #c mort pour l'eq
                    arewestilltrying=False
      #  print besteq,bestlower,da
            
                
    if arewestilltrying:
        print besteq
    else:
        print bestlower