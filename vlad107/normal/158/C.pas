{$r-,q-,s-,i-,o+}
var
  t,s,p:ansistring;
  ch:char;
  tt,i:longint;

begin
  //assign(input,'input.txt');reset(Input);
  //assign(output,'output.txt');rewrite(output);
  readln(tt);
  t:='/';
  while (tt>0)do begin
    dec(tt);
    read(ch);
    if (ch='c')then begin
      read(ch,ch);
      readln(s);
      if (t='/')then t:='';
      if (s[1]='/')then t:='' else s:='/'+s;
      t:=t+s;
      p:='';
      i:=1;
      s:=t;
      while (i<=length(s))do begin
        if (i+1<=length(s))and(s[i]+s[i+1]='..')
          then begin
            delete(p,length(p),1);
            while (length(p)>0)and(p[length(p)]<>'/')do delete(p,length(p),1);
            inc(i,2);
          end else p:=p+s[i];
        inc(i);
      end;
      while (length(p)>0)and(p[length(p)]='/')do delete(p,length(p),1);
      t:=p;
      if (t='')then t:='/';
    end else begin
      readln(s);
      write(t);
      if (t[length(t)]<>'/')then writeln('/')else writeln;
    end;
  end;
  //close(input);close(output);
end.