
n=int(raw_input())
s="0"+raw_input()+"0";

res="No"
for i in range(1,n+1):
    ss=set()
    if s[i-1] in "CMY":
        ss.add(s[i-1])
    if s[i+1] in "CMY":
        ss.add(s[i+1])
    if s[i]=="?":
        if len(ss)<2:
            res="Yes"
    if s[i] in ss:
        res="No"
        break

print res