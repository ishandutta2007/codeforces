const dayofm:array[1..12]of integer=(31,28,31,30,31,30,31,31,30,31,30,31);
var a,b:string;
        i,d1,d2,m1,m2,y1,y2:integer;
procedure solve;
var tmp:integer;ans:longint;
        begin
        ans:=0;
        if a>b then
                begin
                tmp:=y1;y1:=y2;y2:=tmp;
                tmp:=m1;m1:=m2;m2:=tmp;
                tmp:=d1;d1:=d2;d2:=tmp;
                end;
        for i:=1 to m1-1 do
                begin
                if ((i=2) and (((y1 mod 4=0) and (y1 mod 100<>0))or (y1 mod 400=0))) then ans:=ans-29
                else ans:=ans-dayofm[i];
                end;
        ans:=ans-d1;
        for i:=y1 to y2 do if
        (((i mod 4=0) and (i mod 100<>0))or (i mod 400=0)) then ans:=ans+366 else ans:=ans+365;
        for i:=m2 to 12 do
                begin
                if ((i=2) and (((y2 mod 4=0) and (y2 mod 100<>0))or (y2 mod 400=0))) then ans:=ans-29
                else ans:=ans-dayofm[i];
                end;
        ans:=ans+d2;
        write(ans);
        end;
begin
readln(a);
for i:=1 to 4 do y1:=10*y1+ord(a[i])-48;
for i:=6 to 7 do m1:=10*m1+ord(a[i])-48;
for i:=9 to 10 do d1:=10*d1+ord(a[i])-48;
readln(b);
for i:=1 to 4 do y2:=10*y2+ord(b[i])-48;
for i:=6 to 7 do m2:=10*m2+ord(b[i])-48;
for i:=9 to 10 do d2:=10*d2+ord(b[i])-48;
solve;
end.