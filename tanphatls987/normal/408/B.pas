var a,b:ansistring;
    i,ans:integer;
    ha,hb:array[0..25]of integer;
begin
readln(a);
readln(b);
for i:=1 to length(a) do inc(ha[ord(a[i])-97]);
for i:=1 to length(b) do inc(hb[ord(b[i])-97]);
ans:=0;
for i:=0 to 25 do
        begin
        if ((hb[i]>0) and(ha[i]=0)) then begin writeln(-1);halt;end;
        if hb[i]>ha[i] then ans:=ans+ha[i] else ans:=ans+hb[i];
        end;
writeln(ans);
end.