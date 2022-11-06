n=[int(k) for k in raw_input().split(" ")][0]
s=raw_input()
n8=0
for k in s:
    if k=="8":
        n8+=1

res= min(n8,n/11)

print res