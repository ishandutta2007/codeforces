from sys import stdout
l,r,k=map(int,raw_input().split())
num=1
wrong=True
while num<=r:
    if num>=l:
        wrong=False
        stdout.write('%d ' % num)
    num *= k
if wrong:
    print -1