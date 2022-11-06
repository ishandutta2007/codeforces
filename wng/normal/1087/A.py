t=raw_input()

n=len(t)

if n<=2:
    print t
else:
    if n%2:
        nbl=(n-2)/2+1
        s=[t[nbl:nbl+2]]
        for i in range(nbl):
            s+=[t[nbl-1-i]]
            if i<nbl-1:
                s+=t[nbl+2+i]
                assert nbl+2+i<n
            assert nbl-1-i>=0
    else:
        nbl=(n-2)/2
        s=[t[nbl:nbl+2]]
        for i in range(nbl):
            s+=[t[nbl-1-i]]
            s+=t[nbl+2+i]
            assert nbl+2+i<n
            assert nbl-1-i>=0
    print "".join(s)