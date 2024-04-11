x=input()
x=x.lower()
new=""
for char in x:
    if char not in "aeiouy":
        new=new+"."+char
print(new)