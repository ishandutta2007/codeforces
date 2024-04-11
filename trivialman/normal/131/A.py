str1 = input()
if (str1[1:]+'A').isupper():
    if(str1[0].islower()):
        print(str1[0].upper()+str1[1:].lower())
    else:
        print(str1.lower())
else:
    print(str1)