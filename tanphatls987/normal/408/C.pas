var a,b,i,j,tmp,key,pa,pb,x1,y1,x2,y2:longint;
    px1,py1,px2,py2:array[1..1000]of integer;
procedure outfile;
        begin
if ((pa=0)or(pb=0)) then begin writeln('NO');halt;end;
for i:=1 to pa do for j:=1 to pb do if (px1[i]*px2[j]+py1[i]*py2[j]=0) then
        begin
        if (py1[i]=py2[j]) then begin tmp:=px1[i];px1[i]:=-py1[i];py1[i]:=-tmp;tmp:=px2[j];px2[j]:=py2[j];py2[j]:=tmp;end;
        writeln('YES');
        writeln(0,' ',0);
        writeln(px1[i],' ',py1[i]);
        writeln(px2[j],' ',py2[j]);
        halt;
        end;
        writeln('NO');
        end;
begin
readln(a,b);
pa:=0;pb:=0;
for i:=1 to trunc(a/sqrt(2)) do
        begin
        x1:=a*a-i*i;
        if trunc(sqrt(x1))=sqrt(x1) then begin inc(pa);px1[pa]:=-trunc(sqrt(x1));py1[pa]:=-i;end;
        end;
for i:=1 to trunc(b/sqrt(2))do
                begin
                y2:=b*b-i*i;
                if (trunc(sqrt(y2))=sqrt(y2)) then begin inc(pb);py2[pb]:=-trunc(sqrt(y2));px2[pb]:=i;end;
                end;
outfile;
end.