n=int(input())
if n%4==2:
    print('!', '-1')
    exit()
def qry(i):
    print('?', i+1, flush=True)
    a=int(input())
    return a
def qry2(i):
    a=qry(i+n//2)-qry(i)
    if a==0:
        print('!', i+1)
        exit()
    return a
a=qry2(0)
lb,rb=1,n//2-1
while lb<=rb:
    mb=(lb+rb)//2
    b=qry2(mb)
    if (a>0)==(b>0):
        lb=mb+1
    else:
        rb=mb-1