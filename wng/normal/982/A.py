#[int(k) for k in raw_input().split(" ")]
n=int(raw_input())
s="0"+raw_input()+"0"
res="Yes"
for k in range(1,n+1):
    if s[k-1:k+2]=="000":
        res="No"
        break
    if s[k:k+2]=="11":
        res="No"
        break

print res