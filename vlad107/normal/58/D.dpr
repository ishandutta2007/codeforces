type
  tstring=string;
var
  qq,n,dl,i,j:longint;
  ch:char;
  was:array[1..20000]of boolean;
  d:array[1..20000]of longint;
  res,a,b:array[1..20000]of tstring;
  function cmp(x,y,a,b:tstring):boolean;
    begin
      if (length(x)=length(a))then cmp:=x>=a else
      if (length(x)>length(a))then cmp:=x>=b else
      if (length(x)<length(a))then cmp:=y>=a;
    end;
  function cmp2(x,y,a,b:tstring):boolean;
    begin
      if (length(x)=length(a))then cmp2:=x>a else
      if (length(x)>length(a))then cmp2:=x>b else
      if (length(x)<length(a))then cmp2:=y>a;
    end;
  procedure qs(l,r:longint);
    var
      x,y,tmp:tstring;
      t2,i,j:longint;
    begin
      i:=l;j:=r;
      x:=a[(i+j)shr 1];
      y:=b[(i+j)shr 1];
      while (i<=j)do begin
        while (cmp2(x,y,a[i],b[i]))do inc(i);
        while not (cmp(x,y,a[j],b[j]))do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        t2:=d[i];d[i]:=d[j];d[j]:=t2;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
begin
  readln(n);
  dl:=0;
  for i:=1 to n do begin
    readln(a[i]);
    d[i]:=length(a[i]);
    dl:=dl+d[i];
  end;
  dl:=dl*2 div n;
  dl:=dl+1;
  readln(ch);
  for i:=1 to n do b[i]:=a[i]+ch;
  fillchar(was,sizeof(was),false);
  qs(1,n);
  for i:=1 to n div 2 do begin
    for j:=1 to n do
      if (not was[j])then begin
        was[j]:=true;
        qq:=d[j]+1;
        res[i]:=b[j];
        break;
      end;
    for j:=1 to n do
      if (not was[j])and(qq+d[j]=dl)then begin
        was[j]:=true;
        res[i]:=res[i]+a[j];
        break;
      end;
  end;
  for i:=1 to n div 2 do writeln(res[i]);
end.