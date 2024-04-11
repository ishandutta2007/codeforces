s = input()
L = input()
k = int(input())

'''from datetime import *
time1 = datetime.now()'''
good = set()
string = set()
LIST = [chr(i) for i in range(97,123)]
for i in range(26):
    if L[i]=='1':
        good.add(LIST[i])

t = [s[i] not in good for i in range(len(s))]

end = [0]*len(s)
badchars = 0
front=0; rear=0
while(front<len(s)):
    while(rear<len(s)):
        badchars+=t[rear]
        if badchars>k:
            badchars-=1
            break
        rear+=1
    end[front]=rear
    badchars -= t[front]
    front+=1

for i in range(len(s)):
    tempStrHash = 0
    for j in range(i, end[i]):
        tempStrHash = (tempStrHash*29+ord(s[j])-96)&1152921504606846975
        string.add(tempStrHash)
        
print(len(string))
#print(datetime.now()-time1)