x = input()
for i in range(10):
    if list(x) == list(x)[::-1]:
        print("YES") 
        break
    x = "0"+x
else: print("NO")