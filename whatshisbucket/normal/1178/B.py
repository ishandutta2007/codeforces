s=input()
prev="o"
ws=0
for char in s:
    if char==prev=="v":
        ws+=1
    prev=char
tot=0
seen=0
prev="o"
for char in s:
    if char=="o":
        tot+=seen*(ws-seen)
    elif char==prev=="v":
        seen+=1
    prev=char
print(tot)