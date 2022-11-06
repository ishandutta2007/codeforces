nbt=int(input())

for nt in range(nbt):
    n=int(input())
    s=input()
    res=None
    for i in range(26):
        if chr(97+i) not in s:
            res=chr(97+i)
            break
    if res is None:
        for i in range(26):
            if res is not None:
                break
            for j in range(26):
                if chr(97+i)+chr(97+j) not in s:
                    res=chr(97+i)+chr(97+j)
                    break
    
    if res is None:
        for i in range(26):
            if res is not None:
                break
            for j in range(26):
                if res is not None:
                    break
                for k in range(26):
                    if chr(97+i)+chr(97+j)+chr(97+k) not in s:
                        res=chr(97+i)+chr(97+j)+chr(97+k) 
                        break
    print(res)