print("?",0,0)
e=int(input())
astr="000000000000000000000000000000"
bstr="000000000000000000000000000000"
abig=e
for i in range(30):
    if abig==0:
        print("?",int(astr,2)+2**(29-i),int(bstr,2))
        e=int(input())
        if e==1:
            continue
        else:
            if i<29:
                astr=astr[:i]+"1"+astr[i+1:]
                bstr=bstr[:i]+"1"+bstr[i+1:]
            else:
                astr=astr[:i]+"1"
                bstr=bstr[:i]+"1"
    else:
        print("?",int(astr,2)+2**(29-i),int(bstr,2)+2**(29-i))
        e=int(input())
        if e==-abig:
            if abig==1:
                if i<29:
                    astr=astr[:i]+"1"+astr[i+1:]
                else:
                    astr=astr[:i]+"1"
            else:
                if i<29:
                    bstr=bstr[:i]+"1"+bstr[i+1:]
                else:
                    bstr=bstr[:i]+"1"
            print("?",int(astr,2),int(bstr,2))
            abig=int(input())
        else:
            print("?",int(astr,2)+2**(29-i),int(bstr,2))
            e=int(input())
            if e==-1:
                if i<29:
                    astr=astr[:i]+"1"+astr[i+1:]
                    bstr=bstr[:i]+"1"+bstr[i+1:]
                else:
                    astr=astr[:i]+"1"
                    bstr=bstr[:i]+"1"
print("!",int(astr,2),int(bstr,2))