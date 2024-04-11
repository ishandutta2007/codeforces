var
  a:array[0..100500]of longint;
  ss:array[0..1111]of string;
  s,s1,s2:string;
  nax,j,x,y,i,n,kn:longint;
  function fnom(s:string):longint;
    var
      i:longint;
    begin
      i:=1;
      while (i<=kn)and(ss[i]<>s)do inc(i);
      if (i>kn)then i:=-1;
      fnom:=i;
    end;

begin
  readln(n);
  kn:=2;
  a[1]:=0;
  ss[1]:='void';
  a[2]:=-1000000000;
  ss[2]:='errtype';
  for i:=1 to n do begin
    readln(s);
    if (s[5]='d')then begin
      delete(s,1,8);
      s1:=copy(s,1,pos(' ',s)-1);
      delete(s,1,pos(' ',s));
      s2:=s;
      x:=fnom(s2);
      if (x<0)then begin
        inc(kn);
        ss[kn]:=s2;
        x:=kn;
      end;
      nax:=0;
      while (s1[1]='&')do begin
        dec(nax);
        delete(s1,1,1);
      end;
      while (s1[length(s1)]='*')do begin
        inc(nax);
        delete(s1,length(s1),1);
      end;
      if (s1='void')then begin
        a[x]:=nax;continue;
      end;
      y:=fnom(s1);
      if (y<0)or(a[y]<0)then a[x]:=-1000000000 else a[x]:=nax+a[y];
    end else begin
      delete(s,1,7);
      nax:=0;
      while (s[1]='&')do begin
        dec(nax);
        delete(s,1,1);
      end;
      while (s[length(s)]='*')do begin
        inc(nax);
        delete(s,length(s),1);
      end;
      x:=fnom(s);
      if (x<0)or(a[x]<0)or(a[x]+nax<0)
        then writeln('errtype')
        else begin
          write('void');
          for j:=1 to a[x]+nax do write('*');
          writeln;
        end;
    end;
  end;
end.