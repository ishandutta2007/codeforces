a = int(raw_input())
b = raw_input()
i = 0
while i < len(b)-1:
    
    if b[i:i+2] in ["UR","RU"]:
        i+=1
        a-=1
    i+=1
print a