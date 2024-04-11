import java.io.*;
import java.util.*;

public class Solution {
    static Person[] people;
 
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        people = new Person[n];
 
        for (int i = 0; i < n; i++) {
            people[i] = new Person();
            people[i].x = input.nextInt();
        }
 
        for (int i = 0; i < n; i++) {
            people[i].v = input.nextInt();
        }
 
        MergeSort(people);
        /*for (int i = 0; i < people.length; i++) {
            System.out.print(people[i].x + " ");
        }*/
 
        double l = 0, r;
        r = maxTime();
        //System.out.println(r);
       
        double time;
        boolean btime;
       
        while(l + 0.000001 < r){
            time = (l+r)/2;
            btime = test(time);
           
            if(btime == false){
                l = time;
            }else{
                r = time;
            }
        }
       
        System.out.println(r);
    }
   
   
   
    public static double maxTime() {
        double max = (people[people.length - 1].x - people[0].x) / (double)people[0].v;
 
        double m;
        for (int i = 1; i < people.length; i++) {
            m = Math.max((people[i].x - people[0].x) / (double)people[i].v,
                    (people[people.length - 1].x - people[i].x) / (double)people[i].v);
            if (m > max) {
                max = m;
            }
        }
        return max;
    }
 
    public static boolean test(double time) {
        double nx, px, tempnx, temppx;
 
        nx = people[0].x - people[0].v * time;
        px = people[0].x + people[0].v * time;
        for (int i = 1; i < people.length; i++) {
            tempnx = people[i].x - people[i].v * time;
            temppx = people[i].x + people[i].v * time;
 
            if (tempnx > nx) {
                nx = tempnx;
            }
            if (temppx < px) {
                px = temppx;
            }
            if (nx > px) {
                return false;
            }
        }
       
        return true;
    }
 
    // Merge Sort
    public static void MergeSort(Person[] people) {
        sort(people, 0, people.length - 1);
    }
 
    public static void merge(Person[] people, int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;
 
        /* Create temp arrays */
        Person L[] = new Person[n1];
        Person R[] = new Person[n2];
 
        /* Copy data to temp arrays */
        for (int i = 0; i < n1; ++i)
            L[i] = people[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = people[m + 1 + j];
 
        /* Merge the temp arrays */
 
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;
 
        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i].x <= R[j].x) {
                people[k] = L[i];
                i++;
            } else {
                people[k] = R[j];
                j++;
            }
            k++;
        }
 
        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            people[k] = L[i];
            i++;
            k++;
        }
 
        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            people[k] = R[j];
            j++;
            k++;
        }
    }
 
    // Main function that sorts arr[l..r] using
    // merge()
    public static void sort(Person[] people, int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = (l + r) / 2;
 
            // Sort first and second halves
            sort(people, l, m);
            sort(people, m + 1, r);
 
            // Merge the sorted halves
            merge(people, l, m, r);
        }
    }
 
    /* A utility function to print array of size n */
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
 
    // Driver method
 
}
 
class Person {
    int x;
    int v;
}