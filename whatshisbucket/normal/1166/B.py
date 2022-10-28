k=int(input())
mini=4
good=False
while mini<=k**.5:
    mini+=1
    if k%mini==0:
        good=True
        break
if not good:
    print(-1)
else:
    rows=mini
    columns=k//rows
    col1=("aeiou"*columns)[:columns]
    col2=("eioua"*columns)[:columns]
    col3=("iouae"*columns)[:columns]
    col4=("ouaei"*columns)[:columns]
    col5=("uaeio"*columns)[:columns]
    out=col1+col2+col3+col4+col5+col1*(rows-5)
    if columns>=5 and rows>=5:
        print(out)
    else:
        print(-1)