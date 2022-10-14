a = int(raw_input())
b = raw_input()
i = len(b)/2
while i>0:
    if b[:i] == b[i:2*i]:
        print a-i+1
        break
    i-=1
if i==0:
    print a