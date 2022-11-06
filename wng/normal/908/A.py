s=raw_input()
res=0
for i in s:
    if i in "13579aeiou":
        res+=1
print res