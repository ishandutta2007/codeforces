#!/usr/bin/python3

exp = input()
value = str(eval(exp))
for i in range(len(value)):
    for s in range(ord(value[i])):
        print('+', end='')
    print('.>', end='')